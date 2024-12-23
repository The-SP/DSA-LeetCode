# Leetcode Hard
# 1255. Maximum Score Words Formed by Letters
# https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/


def get_letters_count(letters):
    hash = {}
    for letter in letters:
        if letter in hash:
            hash[letter] += 1
        else:
            hash[letter] = 1
    return hash


def can_form_word(word, hash):
    """Check if a word can be formed with the given letters"""
    for letter in word:
        if letter not in hash:
            return False, hash
        else:
            hash[letter] -= 1
            if hash[letter] < 0:
                return False, hash 
    return True, hash


def get_words_score(words, score):
    hash = {}
    for word in words:
        sum = 0
        for letter in word:
            idx = ord(letter) - ord('a')
            sum += score[idx]
        hash[word] = sum
    return hash


def max_score_words(words, letters, score):
    hash = get_letters_count(letters)
    word_score = get_words_score(words, score)
    result = []
    
    def backtrack(start, path, hash):
        if start == len(words):
            if path:
                result.append(path)
            return 
        
        # Include the current word if possible
        word_valid, new_hash = can_form_word(words[start], hash.copy())
        if word_valid:
            backtrack(start+1, path+[words[start]], new_hash)
            
        # Exclude the current word
        backtrack(start+1, path, hash.copy())
        

    backtrack(0, [], hash.copy())
    
    # Find the maximum score among valid set of words
    max_score = 0
    for words in result:
        sum = 0
        for word in words:
            sum += word_score[word]
        if sum > max_score:
            max_score = sum

    print(result)
    return max_score


words = ["xxxz","ax","bx","cx"]
letters = ["z","a","b","c","x","x","x"]
score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]

print(max_score_words(words, letters, score))