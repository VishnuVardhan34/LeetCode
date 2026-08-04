// Last updated: 8/4/2026, 12:23:07 PM
impl Solution {
    pub fn most_words_found(sentences: Vec<String>) -> i32 {
        let mut max_words=0;
        for sentence in sentences {
            let mut count =1;
            for ch in sentence.chars(){
                if ch == ' ' {
                    count +=1;
                }
            }
            max_words=max_words.max(count);
        }
        return max_words;        
    }
}