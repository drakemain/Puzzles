module.exports = arr => {
    let nextSpaceIndex = arr.indexOf(' ');
    let end = arr.length - 1;
    let counter = 0;

    while (end > nextSpaceIndex) {
        shift(nextSpaceIndex, end,  arr);

        end -= nextSpaceIndex + 1;
        nextSpaceIndex = arr.indexOf(' ');
    }

    return arr;
}

let shift = (lowerBound, upperBound, arr) => {
    while (lowerBound >= 0) {
        let temp = lowerBound > 0 ? arr[lowerBound - 1] : ' ';

        for (let i = lowerBound; i < upperBound; ++i) {
            arr[i] = arr[i + 1];
        }

        arr[upperBound] = temp;

        --lowerBound;
        --upperBound;
    }
}
