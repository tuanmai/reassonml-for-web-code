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
  switch(str) {
    | "S" => Some(Small)
    | "M" => Some(Medium)
    | "L" => Some(Large)
    | "XL" => Some(Xlarge(1))
    | "XXL" => Some(Xlarge(2))
    | "XXXL" => Some(Xlarge(3))
    | _ => None
  }
}

Js.log(price(Medium))                                                                                                     
Js.log(shirtSizeOfString("XL"))                                                                                                     
Js.log(shirtSizeOfString("XLBN"))                                                                                                     
