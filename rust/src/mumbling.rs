/*
https://www.codewars.com/kata/5667e8f4e3f572a8f2000039
 */

fn accum(s:&str)->String {
    let mut result = String::new();

    for (i, char) in s.chars().enumerate() {
        result.push_str(char.to_uppercase().to_string().as_str());
        
        for j in 0..i {
            result.push_str(char.to_lowercase().to_string().as_str());
        }
        
        result.push_str("-");
    }
    
    result.pop();
    
    result
}


#[test]
fn basic_tests() {
  assert_eq!(accum("ZpglnRxqenU"), "Z-Pp-Ggg-Llll-Nnnnn-Rrrrrr-Xxxxxxx-Qqqqqqqq-Eeeeeeeee-Nnnnnnnnnn-Uuuuuuuuuuu");
  assert_eq!(accum("NyffsGeyylB"), "N-Yy-Fff-Ffff-Sssss-Gggggg-Eeeeeee-Yyyyyyyy-Yyyyyyyyy-Llllllllll-Bbbbbbbbbbb");
  assert_eq!(accum("MjtkuBovqrU"), "M-Jj-Ttt-Kkkk-Uuuuu-Bbbbbb-Ooooooo-Vvvvvvvv-Qqqqqqqqq-Rrrrrrrrrr-Uuuuuuuuuuu");
  assert_eq!(accum("EvidjUnokmM"), "E-Vv-Iii-Dddd-Jjjjj-Uuuuuu-Nnnnnnn-Oooooooo-Kkkkkkkkk-Mmmmmmmmmm-Mmmmmmmmmmm");
  assert_eq!(accum("HbideVbxncC"), "H-Bb-Iii-Dddd-Eeeee-Vvvvvv-Bbbbbbb-Xxxxxxxx-Nnnnnnnnn-Cccccccccc-Ccccccccccc");
}