// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';


var wind_chill = 13.12 + 0.6215 * 30.0 - 11.37 * Math.pow(60.0, 0.36);

console.log("At temperature " + ((30.0).toString() + (" degrees C and wind speed " + ((60.0).toString() + " km/h"))));

var temperature = 30.0;

var velocity = 60.0;

exports.temperature = temperature;
exports.velocity = velocity;
exports.wind_chill = wind_chill;
/* wind_chill Not a pure module */
