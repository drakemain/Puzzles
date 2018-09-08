// Given a positive integer, create and array containing all
// preceeding prime numbers.

function trialDivision(input) {
  var primeArr = [];

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

exports.trialDivision = trialDivision;

function eratosthenes(input) {
  var is_prime = new Array(input + 1);
  var primes = [];

  for (var i = 2; i <= input; i++) {
    is_prime[i] = true;
  };

  for (var i = 2; i <= input; i++) {
    if (is_prime[i]) {
      primes.push(i);

      for (var j = i; j <= input; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return primes;
}

exports.eratosthenes = eratosthenes;

function eratosthenes2(input) {
  let list = new Array(input - 2);
  let sqrtInput = Math.sqrt(input);

  for (let i = 2; i <= input; ++i) {
    list[i-2] = Number(i);
  }

  for (let i = 0; i < sqrtInput; ++i) {
    for (let j = i + list[i]; j < list.length; j += list[i]) {
      console.log('Prime value: ' + list[i]);
      console.log(' index: ' + j + ` (${list[j]})`);

      if (list[i] == 0) {
        break;
      }

      list[j] = 0;
    }
  }

  for (val in list) {
    if (list[val] !== 0) {
      console.log('  ' + list[val]);  
    }
  }
}

eratosthenes2(100);