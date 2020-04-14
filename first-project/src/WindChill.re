let temperature = 30.0
let velocity = 60.0

let wind_chill = 13.12 +. (0.6215 *. temperature) -. (11.37 *. (velocity ** 0.36))

Js.log("At temperature " ++ Js.Float.toString(temperature) ++ " degrees C and wind speed " ++ Js.Float.toString(velocity) ++ " km/h")
