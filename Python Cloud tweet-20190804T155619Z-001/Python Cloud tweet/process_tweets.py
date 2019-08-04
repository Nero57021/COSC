'''
    Jeremy Bayangos
	Designated use for reading twitter
'''


def clean_line(line):
    '''
    "Twitter for iPhone,China is @sending an Envoy and Delegation to North Korea - A big move we'll see what happens!,11-16-2017 12:43:05,9531,41497,false,931140567089721344"
    Eliminates all non-alphabetical characters, except ' ', '@'' and '#',
    from the line.
    >>> clean_line("This is a #hashtag!, this a is a Number123  @userName")
    'this is a #hashtag this a is a number  @username'

    Hint: you can check if a character is alphabetical with this
    expression:
    `char in ascii_letters`
    '''
    # your code here
    base_string = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ @#'

    sub = ''
    for char in line:
        if char not in base_string:
            line = line.replace(char, sub)

    line = line.lower()
    return line


def read_stopwords():
    '''
    Read the stopwords from 'stopwords.txt' file and return list with the words
    '''
    # your code here
    lst = []
    words = open('stopwords.txt')
    for line in words:
        word = line.split('\n')
        lst.append(word[0])
    return lst


def get_tweet_text(line1):
    '''
    Receives a line from the tweets file and get the twwet text from it
    and return all the words in a list.
    The line has the following structure:
    source, text,created_at, retweet_count, favorite_count, is_retweet,id_str

    >>> get_tweet_text("Twitter,Thank you!,11-15-2017 10:58:18,96,433,false,9307")
    'Thank you!'
    '''
    # your code here
    lst = line1.split(',')
    line1 = lst[1]
    return line1


def process_tweet_text(text):
    '''
    Receives the tweet text and process it:
    - eliminates any non-alpabetical character, except ' ', '@'' and '#'
    - convert it to lowercase
    - separates it in words
    - filter out all the words which are stopwords
    - return the remaining words as a list
    >>> process_tweet_text("this is a #hashtag this a is a number  @username")
    ['#hashtag', 'number', '@username']
    '''
    stopwords = read_stopwords()
    words = clean_line(text).split()
    result = []
    # your code here
    for elem in words:
        if elem not in stopwords:
            result.append(elem)

    return result


def process_tweet_file(file_name):
    '''
    Receives the name of file contanining tweets. Process it to get
    all the tweet texts. Extract the words from it and count their frequencies
    Return the result as a dictionary, where the key are the words and the
    values are the word frequencies.
    '''
    word_freqs = {}
    words_list = []

    with open(file_name) as tweets:
        for line in tweets:
            text = get_tweet_text(line)
            words = process_tweet_text(text)
            for i in words:
                words_list.append(i)

        for item in words_list:
            word_freqs[item] = words_list.count(item)

    return word_freqs


def print_statistics(word_freqs):
    '''
    Receives a dictionary with word frequencies and print statistics.
    '''
    # your code here
    tot_num_of_words = sum(word_freqs.values())
    tot_num_of_different_words = len(word_freqs.keys())
    most_frequent_word = max(word_freqs, key=word_freqs.get)
    most_frequent_word_freq = word_freqs[most_frequent_word]
    print('The total number of words is:', tot_num_of_words)
    print('The total number of different words is:', tot_num_of_different_words)
    print('The most frequent word is:', most_frequent_word)
    print('With a frequency of:', most_frequent_word_freq)


def write_words(word_freqs, file_name):
    '''
    Write down the words along with their frequencies, one word per line
    with the word and the frequency separated by a space:
            great 484
            fabulous 200
    '''
    # your code here
    file = open(file_name, 'w')
    for key, val in word_freqs.items():
        val = str(val)
        file.write('{} {}\n'.format(key, val))
    file.close()


wf = process_tweet_file('tweets.txt')
print_statistics(wf)
write_words(wf, 'words.txt')