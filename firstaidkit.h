#ifndef FIRSTAIDKIT_H
#define FIRSTAIDKIT_H

#include "item.h"

namespace xcom {

class FirstAidKit : public Item {
  // Оставшееся кол-во использований
  int qty;
  // Кол-во использований
  int maxQty;
  // Кол-во восстанавливающего здоровья
  int rec;
  // Вес одного "заряда" аптечки
  double weightOfOne;

 protected:
  virtual std::ostream &print(std::ostream &) const noexcept override;

 public:
  // Конструктор, создающий полную аптечку с 3-мя использованиями,
  // восстанавливающую 2 HP и тратящую на использование 2 TP
  FirstAidKit(int up = 2, int hp = 2, double w = 0.5, int maxqty = 3);

  // copy- move- конструкторы по умолчанию

  // Виртуальный деструктор класса "Аптечка"
  virtual ~FirstAidKit() override{};

  int get_qty() const noexcept { return qty; };
  int get_maxQty() const noexcept { return maxQty; };
  int get_rec() const noexcept { return rec; };
  double get_weightOfOne() const noexcept { return weightOfOne; };

  // Проверка аптечки на пустоту
  bool isEmpty() const noexcept;

  FirstAidKit &set_qty(int);
  FirstAidKit &set_maxQty(int);
  FirstAidKit &set_rec(int);
  FirstAidKit &set_weightOfOne(double);

  // Пересчет веса аптечки
  virtual void set_weight(double) override {
    Item::set_weight(weightOfOne * qty);
  };

  /*
        Использование аптечки: потратить один заряд и вернуть кол-во полученных
   HP. Если аптечка пуста, то ничего не происходит (возвращается 0)
 */
  virtual int using_item() override;

  /*
      Сохранение информации об аптечке в выходном/файловом потоке:
  Информация: 'очки использования'_'кол-во использований'_'макс. кол-во
  использований'_'кол-во восстановливаемого ХП'_'вес одного использования' Вес
  высчитывается отдельно
  */
  virtual std::ostream &save(std::ostream &) const noexcept override;

  // Загрузка информации об аптечке из входного/файлового потока
  virtual std::istream &load(std::istream &) noexcept override;

  // Создание копии аптечки
  virtual FirstAidKit *clone() const noexcept override {
    return new FirstAidKit(*this);
  };

  // Вывод информации об аптечке в выходной поток
  friend std::ostream &operator<<(std::ostream &os,
                                  const FirstAidKit &c) noexcept {
    return c.print(os);
  };
};

}  // namespace xcom

#endif  // !FIRSTAIDKIT_H
