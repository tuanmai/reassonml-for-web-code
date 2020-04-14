type color =
  | White
  | Black
  | Gray(float)
  | RGB(int, int, int);

let stringOfColorSpec = (cspec: color): string => {
  switch (cspec) {
  | White => "rgb(255, 255, 255)"
  | Black => "rgb(0, 0, 0)"
  | Gray(_) => "rgb(127, 127, 127)"
  | RGB(r, g, b) => {j|rgb($r, $g, $b)|j}
  };
};

Js.log(stringOfColorSpec(White));
Js.log(stringOfColorSpec(RGB(123, 242, 213)));
