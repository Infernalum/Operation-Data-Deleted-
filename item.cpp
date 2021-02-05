#include "item.h"

namespace xcom {

Item::Item(const int ID, const int usedPoint) : weight_(0), ID_(ID) {
  if (usedPoint >= 0) {
    usedPoint_ = usedPoint;
  } else {
    throw std::invalid_argument(constatnts::itemExceptionTP);
  }
}

Item& Item::setUsedPoint(const int usedPoint) {
  if (usedPoint >= 0) {
    usedPoint_ = usedPoint;
  } else {
    throw std::invalid_argument(constatnts::itemExceptionTP);
  }
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
