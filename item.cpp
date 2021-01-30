#include "item.h"

namespace xcom {

Item::Item(int id, int uP) : weight(0), ID(id) {
  if (uP < 1)
    throw std::invalid_argument(
        "Количество затрачиваемых TP должно быть положительным. Попробуйте еще "
        "раз.");
  usedPoint = uP;
}

void Item::set_weight(double val) {
  if (val < 0)
    throw std::invalid_argument(
        "Вес предмета не может быть отрицательным. Попробуйте еще раз.");
  weight = val;
}

void Item::set_usedPoint(int uP) {
  if (uP < 1)
    throw std::invalid_argument(
        "Кол-во расходных очков времени должно быть положительным. Попробуйте "
        "еще раз.");
  usedPoint = uP;
}

std::ostream& Item::print(std::ostream& os) const noexcept {
  os << weight << " кг; TP: " << usedPoint << "; ";
  return os;
}

std::ostream& Item::save(std::ostream& os) const noexcept {
  os.write((char*)&ID, sizeof(ID));
  os.write((char*)&usedPoint, sizeof(usedPoint));
  return os;
}

std::istream& Item::load(std::istream& is) noexcept {
  is.read((char*)&usedPoint, sizeof(usedPoint));
  return is;
}

}  // namespace xcom
