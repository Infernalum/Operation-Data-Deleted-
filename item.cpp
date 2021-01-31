#include "item.h"

namespace xcom {

Item::Item(int id, int uP) : weight_(0), ID_(id) {
  if (uP < 1)
    throw std::invalid_argument(
        "Количество затрачиваемых TP должно быть положительным. Попробуйте еще "
        "раз.");
  usedPoint_ = uP;
}

Item& Item::setUsedPoint(const int usedPoint) {
  if (usedPoint < 1)
    throw std::invalid_argument(
        "Кол-во расходных очков времени должно быть положительным. Попробуйте "
        "еще раз.");
  usedPoint_ = usedPoint;
  return *this;
}

std::ostream& Item::print(std::ostream& os) const noexcept {
  os << weight_ << " кг; TP: " << usedPoint_ << "; ";
  return os;
}

std::ostream& Item::save(std::ostream& os) const noexcept {
  os.write((char*)&ID_, sizeof(ID_));
  os.write((char*)&usedPoint_, sizeof(usedPoint_));
  return os;
}

std::istream& Item::load(std::istream& is) noexcept {
  is.read((char*)&usedPoint_, sizeof(usedPoint_));
  return is;
}

}  // namespace xcom
