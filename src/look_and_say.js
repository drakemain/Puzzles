// The look-and-say sequence starts with 1. Subsequent numbers are constructed
// by "reading the count of each digit and the digit out loud." That is, in the
// first number there is "one one" so the second number is 11. In the second
// number there is "two ones" so the third number is "21."
// 
// 1
// 11,
// 21
// 1211
// 111221
// 312211
// 13112221
// 1113213211

module.exports = function(input) {
  if (input <= 0) {
    return "0";
  }

  var output = "1";
  var counter, lookingAt, instance;
  
  for (var i = 2; i <= input; i++) {
    lookingAt = output.charAt(0);
    counter = 0;
    instance = "";

    for (var j = 0; j <= output.length; j++) {
      if (lookingAt === output.charAt(j)) {
        counter++;
      } else {
        instance += counter.toString() + lookingAt;
        counter = 1;
        lookingAt = output.charAt(j);
      }
    }
    output = instance;
  }
  
  return output;
}