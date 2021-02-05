#ifndef __ITEM_H_INCLUDED___
#define __ITEM_H_INCLUDED__

#include <stdio.h>

#include <iostream>

#include "Constants.h"
namespace xcom {

class Item {
 public:
  /* Правило: никогда не вызывать виртуальные функции в теле конструкторов или
   * деструкторов базовых классов */
  /* Копирующие/перемещающие конструкторы по умолчанию */

  Item(const int ID = constatnts::itemDefaultID,
       const int usedPoint = constatnts::itemDefaultUsedPoint);

  virtual ~Item() = default;

  inline auto getWeight() const noexcept { return weight_; };
  inline auto getUsedPoint() const noexcept { return usedPoint_; };
  inline auto getID() const noexcept { return ID_; };

  /*
   Пересчет веса предмета: для каждого типа предмета свой метод подсчета веса
 */
  virtual Item& computeWeight() = 0;

  Item& setUsedPoint(const int usedPoint);

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
  int usedPoint_;
  double weight_;
  int ID_;
};

}  // namespace xcom

#endif  // !__ITEM_H_INCLUDED__
