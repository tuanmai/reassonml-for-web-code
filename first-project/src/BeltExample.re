let toFloat = (str: string): option(float) => {
  let result = (Js.Float.fromString(str));
  if (Js.Float.isNaN(result)) {
    None
  } else {
    Some(result)
  }
}

let cube = (x: float): float => x *. x *. x;

let reciprocal = (x: float): option(float) => {
  if (x !== 0.0) {
    Some(1.0 /. x)
  } else {
    None
  }
}

let makeDisplayText = (s: option(string)): string => {
  switch(s) {
    | Some(value) => "The result is " ++ value
    | None => "Invalid input"
  }
}

let method1 = (input: string): unit => {
  toFloat(input)
    -> Belt.Option.flatMap(reciprocal)
    -> Belt.Option.map(cube)
    -> Belt.Option.map(Js.Float.toFixedWithPrecision(~digits=3))
    -> makeDisplayText
    -> Js.log
}

method1("0.032")
