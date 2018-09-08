/*
Return the complementary strand of DNA.
 */


fn DNA_strand(dna: &str) -> String {
  dna
  .chars()
  .map(|c| {
      match c {
          'A' => 'T',
          'T' => 'A',
          'G' => 'C',
          'C' => 'G',
          _ => 'X'
      }
  })
  .collect()
}

#[test]
fn test_DNA_strand() {
  assert_eq!(DNA_strand("ATGC"), "TACG");
  assert_eq!(DNA_strand("TACG"), "ATGC");
  assert_eq!(DNA_strand("AAATTTGGGCCC"), "TTTAAACCCGGG");
}