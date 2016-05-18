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

asString = function(input) {
  if (input <= 0) {return "0";}

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

exports.asString = asString;

noString = function(iterations) {
  if (iterations <= 0) {return 0;}

  output = 1;

  while (iterations > 1) {
    iterations--;
    output = generateNextNum(output);
  }

  return output;
}

exports.noString = noString;

function generateNextNum(num) {
  var onesPlaceValue, lookingAt;
  var instance = 0;
  var counter = 0;
  var output = 1;
  var place = 0;

  while (num > 0) {
    onesPlaceValue = num % 10;
    num = (num - onesPlaceValue) / 10;
    
    if (!lookingAt) {
      lookingAt = onesPlaceValue;
      counter = 1;
    } else if (lookingAt !== onesPlaceValue) {
      instance = (counter * Math.pow(10, place + 1))
        + (lookingAt * Math.pow(10, place))
        + (instance);

      place += 2;
      lookingAt = onesPlaceValue;
      counter = 1;
    } else {
      counter++;
    }
  }

  instance = (counter * Math.pow(10, place + 1))
    + (lookingAt * Math.pow(10, place))
    + (instance);

  return instance;
}