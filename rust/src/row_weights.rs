/*
https://www.codewars.com/kata/5abd66a5ccfd1130b30000a9
 */

fn row_weights(array: Vec<u32>) -> (u32, u32) {
    let mut team1: u32 = 0;
    let mut team2: u32 = 0;
    
    for (i, val) in array.iter().enumerate() {
        if i % 2 == 0 {
            team1 += val;
        } else {
            team2 += val;
        }
    }
    
    (team1, team2)
}


#[test]
fn basic_tests() {
  assert_eq!(row_weights(vec![13, 27, 49]), (62, 27));
  assert_eq!(row_weights(vec![50, 60, 70, 80]), (120, 140));
  assert_eq!(row_weights(vec![80]), (80,0));
}