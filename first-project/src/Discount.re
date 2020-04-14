let calDiscount = (~price, ~discount) => price *. discount /. 100.0;
let halfOf = calDiscount(~discount=50.0);
let tenPercentof = calDiscount(~discount=10.0);

Js.log2("Half of", halfOf)
Js.log(halfOf(~price=1000.0))
Js.log(tenPercentof)
Js.log(tenPercentof(~price=1000.0))

