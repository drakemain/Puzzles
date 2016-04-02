var assert = require('assert');

var arr = [1, 2, 3, 5, 5, 7, 9, 9, 11, 11, 11, 13];
var expected = [1, 2, 3, 5, 7, 9, 11, 13, 0, 0, 0, 0];

function dupesToZero(input) {
  for (var i = 0; i < input.length - 1 ; i++) {
    if (input[i] === 0) {
      return;
    }

    if (input[i] === input[i + 1]) {
      input[i] = 0;
      shift(input, i);
      i--;
    }
  }
}

function shift(input, index) {
  var elementAtStartIndex = input[index];

  for (var i = index; i < input.length - 1; i++) {
    input[i] = input[i + 1];
  }

  input[input.length - 1] = elementAtStartIndex;
}

console.time('runtime');
console.log(arr, 'start');
dupesToZero(arr);
console.log(arr, 'final');
console.log(expected, 'expected');
console.timeEnd('runtime');
assert.deepEqual(arr, expected);