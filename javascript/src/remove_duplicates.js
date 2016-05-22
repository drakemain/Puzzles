// Given a sorted array, remove any repeated elements.
// 
// Given  {2, 3, 5, 5, 7,  11, 11, 11, 13}
// expect {2, 3, 5, 7, 11, 13, 0,  0,  0}

module.exports = function removeDuplicates(input) {
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