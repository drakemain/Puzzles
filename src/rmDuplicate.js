module.exports = function dupesToZero(input) {
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