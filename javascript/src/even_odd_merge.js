var List = require('./linked_list').List;

module.exports = function(head) {
  var lookingAt = head,
      evenTail,
      oddHead,
      oddTail,
      index = 0;

  while (lookingAt !== null) {
    if (index % 2 === 0) {
      if (evenTail) {
        evenTail.next = lookingAt;
        oddTail.next = lookingAt.next;
      }

      evenTail = lookingAt;

    } else {
      if (oddHead) {
        oddTail.next = lookingAt;
        oddTail = lookingAt;
      } else {
        oddHead = lookingAt;
        oddTail = lookingAt;
      }
    }
    index++;
    lookingAt = lookingAt.next;
  }

  evenTail.next = oddHead;
}