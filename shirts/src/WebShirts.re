module D = Webapi.Dom;
module Doc = Webapi.Dom.Document;
module Elem = Webapi.Dom.Element;

type shirtSize =
  | Small
  | Medium
  | Large
  | Xlarge(int);

let price = (size: shirtSize): float => {
  switch (size) {
  | Small => 11.0
  | Medium => 20.0
  | Large => 23.0
  | Xlarge(1) => 25.0
  | Xlarge(2) => 30.0
  | Xlarge(_) => 40.0
  };
};

let shirtSizeOfString = (str: string): option(shirtSize) => {
  switch (str) {
  | "S" => Some(Small)
  | "M" => Some(Medium)
  | "L" => Some(Large)
  | "XL" => Some(Xlarge(1))
  | "XXL" => Some(Xlarge(2))
  | "XXXL" => Some(Xlarge(3))
  | _ => None
  };
};

let calculate = (_event: Dom.event): unit => {
  let getValue = (element: option(Elem.t)): option(string) => {
    element
    ->Belt.Option.map(_, Elem.unsafeAsHtmlElement)
    ->Belt.Option.map(_, D.HtmlElement.value);
  };

  let toInt = (s: string): option(int) => {
    switch (int_of_string(s)) {
    | result => Some(result)
    | exception (Failure(_)) => None
    };
  };

  let quantity =
    getValue(Doc.getElementById("quantity", D.document))
    ->Belt.Option.flatMap(_, toInt);

  let unitPrice =
    getValue(Doc.getElementById("size", D.document))
    ->Belt.Option.flatMap(_, shirtSizeOfString)
    ->Belt.Option.map(_, price);

  let totalPrice =
    switch (unitPrice, quantity) {
    | (Some(uPrice), Some(qty)) => Some(uPrice *. float_of_int(qty))
    | (_, _) => None
    };

  let priceString =
    switch (totalPrice) {
    | Some(total) => Js.Float.toFixedWithPrecision(total, ~digits=3)
    | None => ""
    };

  let _ = Doc.getElementById("price", D.document)
    ->Belt.Option.map(_, Elem.setInnerText(_, priceString));
  ();
};

let calcButton = Doc.getElementById("calculate", D.document);
let quantityInput = Doc.getElementById("quantity", D.document);
let sizeInput = Doc.getElementById("size", D.document);

switch (quantityInput) {
| Some(element) =>
  D.EventTarget.addEventListener(
    "change",
    calculate,
    Elem.asEventTarget(element),
  )
| None => ()
};

switch (sizeInput) {
| Some(element) =>
  D.EventTarget.addEventListener(
    "change",
    calculate,
    Elem.asEventTarget(element),
  )
| None => ()
};
