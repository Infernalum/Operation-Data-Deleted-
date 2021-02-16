#include "item.h"

namespace items {

Item& Item::setUsedPoint(const int usedPoint) {
  if (usedPoint >= 0) {
    usedPoint_ = usedPoint;
  } else {
    throw std::invalid_argument(constatnts::itemExceptionTP);
  }
  return *this;
}

Item& Item::setCurQty(const int curQty) {
    if (curQty < 0)
        throw std::invalid_argument(constatnts::AmmoBoxExceptionQty);
    if (curQty > maxQty_)
        curQty_ = maxQty_;
    curQty_ = curQty;
    computeWeight();
    return *this;
}

Item& Item::setMaxQty(const int maxQty) {
    if (maxQty < 0)
        throw std::invalid_argument(constatnts::AmmoBoxExceptionMaxQty);
    maxQty_ = maxQty;
    if (curQty_ > maxQty_) {
        curQty_ = maxQty_;
        computeWeight();
    }
    return *this;
}

std::ostream& Item::print(std::ostream& os) const noexcept {
  os << weight_ << " kg.; TP: " << usedPoint_ << "; ";
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
