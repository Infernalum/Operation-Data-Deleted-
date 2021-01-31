#ifndef __CONSTANTS_H_
#define __CONSTANTS_H_

#include "string"

namespace constatnts {

/*
 For Item:
*/
enum ItemID { ID_AMMOBOX = 1, ID_FIRSTAIDKIT, ID_WEAPON };
constexpr auto defaultItemID = ID_FIRSTAIDKIT;
constexpr auto defaultItemUsedPoint = 1;
const std::string exceptionItemTP =
    "Количество затрачиваемых TP должно быть положительным. Попробуйте еще "
    "раз.";

}  // namespace constatnts

#endif  // __CONSTANTS_H_
