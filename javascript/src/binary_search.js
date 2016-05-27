module.exports.array = function(arr, value) {
  var leftBound = 0
  , rightBound = arr.length - 1
  , middle;
      

  while (leftBound <= rightBound) {
    middle = Math.floor((rightBound - leftBound) / 2) + leftBound;

    console.log(leftBound, middle, rightBound);
    console.log(value);

    if (arr[middle] === value) {
      return true;

    } else if (arr[middle] < value) {
      leftBound = middle + 1;

    } else if (arr[middle] > value) {
      rightBound = middle - 1;
    }
  }
  return false;
};