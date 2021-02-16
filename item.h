#ifndef __ITEM_H_INCLUDED___
#define __ITEM_H_INCLUDED__

#include <stdio.h>
#include <iostream>
#include "Constants.h"

namespace items {

class Item {
 public:
  /* Правило: никогда не вызывать виртуальные функции в теле конструкторов или
   * деструкторов базовых классов */

  /* Копирующие/перемещающие конструкторы по умолчанию */
  Item(const int ID, const int usedPoint, const int maxQty, const int curQty)
      : ID_(ID),
        usedPoint_(usedPoint),
        maxQty_(maxQty),
        curQty_(curQty),
        weight_(0){};

  virtual ~Item() = default;

  inline auto getID() const noexcept { return ID_; };
  inline auto getWeight() const noexcept { return weight_; };
  inline auto getMaxQty() const noexcept { return maxQty_; };
  inline auto getCurQty() const noexcept { return curQty_; };
  inline auto getUsedPoint() const noexcept { return usedPoint_; };

  /*
 Пересчет веса предмета: для каждого типа предмета свой метод подсчета веса
*/
  virtual Item& computeWeight() = 0;

  Item& setUsedPoint(const int usedPoint);
  Item& setMaxQty(const int);
  Item& setCurQty(const int);

  virtual Item& usingItem() = 0;

  /*
 Вывод базовой информации о предмете (не для сохранения в файл, а вывода в
 выходной поток)
*/
  inline friend std::ostream& operator<<(std::ostream& os,
                                         const Item& item) noexcept {
    return item.print(os);
  };

  /*
 Виртуальный метод сохранения базовой информации о предмете в бинарный файл:
 usedPoint_ + weight_ */
  virtual std::ostream& save(std::ostream&) const noexcept;

  /*
 Виртуальный метод загрузки базовой информации о предмете из бинарного файла:
 UsedPoint_ + weight_
  */
  virtual std::istream& load(std::istream&) noexcept;

  virtual Item* clone() const noexcept = 0;

 protected:
  /*
Установка веса предмета через базовый класс. Доступ к нему из вне класса
иметь нельзя
*/
  Item& setWeight(const double);

  virtual std::ostream& print(std::ostream&) const noexcept;

 private:
  int                   ID_;
  int                   usedPoint_;
  int                   maxQty_;
  int                   curQty_;
  double                weight_;
};

}  // namespace items

#endif  // !__ITEM_H_INCLUDED__
