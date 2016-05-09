var List = require('./linked_list').List;

module.exports = function(head) {
	var lookingAt = head,
			evenTail,
			oddHead,
			oddTail;

	while (lookingAt !== null) {
		console.log(lookingAt.value);
		if (lookingAt.value % 2 === 0) {
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
		lookingAt = lookingAt.next;
	}

	evenTail.next = oddHead;
}