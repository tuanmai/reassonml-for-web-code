// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';


function price(size) {
  if (typeof size === "number") {
    switch (size) {
      case /* Small */0 :
          return 11.0;
      case /* Medium */1 :
          return 20.0;
      case /* Large */2 :
          return 23.0;
      
    }
  } else {
    var match = size[0];
    if (match !== 1) {
      if (match !== 2) {
        return 40.0;
      } else {
        return 30.0;
      }
    } else {
      return 25.0;
    }
  }
}

function shirtSizeOfString(str) {
  switch (str) {
    case "L" :
        return /* Large */2;
    case "M" :
        return /* Medium */1;
    case "S" :
        return /* Small */0;
    case "XL" :
        return /* Xlarge */[1];
    case "XXL" :
        return /* Xlarge */[2];
    case "XXXL" :
        return /* Xlarge */[3];
    default:
      return ;
  }
}

console.log(price(/* Medium */1));

console.log(shirtSizeOfString("XL"));

console.log(shirtSizeOfString("XLBN"));

exports.price = price;
exports.shirtSizeOfString = shirtSizeOfString;
/*  Not a pure module */
