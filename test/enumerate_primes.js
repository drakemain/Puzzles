var chai = require('chai');
var assert = chai.assert;

var enumeratePrimes = require('./../src/enumerate_primes');

describe('Enumerate Primes - Trial Division', function() {
  it('should have all primes preceeding given integer', function() {
    assert.deepEqual(enumeratePrimes.trialDivision(18), [2, 3, 5, 7, 11, 13, 17]);
  });
});

describe('Enumerate Primes - Eratosthenes', function() {
  it('should have all primes preceeding given integer', function() {
    assert.deepEqual(enumeratePrimes.eratosthenes(18), [2, 3, 5, 7, 11, 13, 17]);
  });
});