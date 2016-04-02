module.exports = function enumeratePrimes(input) {
  primeArr = [];

  for (var numerator = 2; numerator <= input; numerator++) {
    var isPrime = true;

    for (var denominator = 2; denominator < numerator; denominator++) {

      if (numerator % denominator === 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) {
      primeArr.push(numerator);
    }
  }

  return primeArr;
}