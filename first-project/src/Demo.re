Js.log("Hello, BuckleScript and Reason!");

let qty = 7;
let price = 15;
let total = qty * price;
let bad1 = if (qty < 0) { 0.05; } else { 0.0 }
Js.log2("The total price is $", total);

let avg = (a, b) => {
  (a +. b) /. 2.0
}

let result = avg(3.0, 4.5);
Js.log(Js.Float.toFixedWithPrecision(result, ~digits=3));

let payment = (~principle, ~apr, ~years) => {
  let r = apr /. 12.0 /. 100.0;
  let n = float_of_int(years  * 12);
  let powerTerm = (1.0 +. r) ** n;
  principle *. (r *. powerTerm) /. (powerTerm -. 1.0);
}

let amount = payment(~principle=10000.0, ~apr=-5.0, ~years=30)
Js.log2("ammount: ", Js.Float.toFixedWithPrecision(amount, ~digits=3))

let sqr = x => x * x

Js.log2("Average of 3? ", avg(3.9))
