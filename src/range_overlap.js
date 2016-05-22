module.exports = function(a, b, c, d) {
  if (c <= b && d > b) {
    return true;
  } else if (a <= d && b > c) {
    return true;
  } else {
    return false;
  }
}