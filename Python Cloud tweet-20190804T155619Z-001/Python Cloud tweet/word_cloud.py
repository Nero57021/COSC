'''
Project for class by Jeremy Bayangos
Designated purpose of reading tweets and tracking of certain words.
Make the necessary changes as necessary
'''

HTML_page_header = '''
<!DOCTYPE html>
<html>
<script src="http://d3js.org/d3.v3.min.js"></script>
<script src="d3.layout.cloud.js"></script>
<head>
    <title>Word Cloud Example</title>
</head>
<style>
    body {
        font-family:"Lucida Grande","Droid Sans",Arial,Helvetica,sans-serif;
    }
    .legend {
        border: 1px solid #555555;
        border-radius: 5px 5px 5px 5px;
        font-size: 0.8em;
        margin: 10px;
        padding: 8px;
    }
    .bld {
        font-weight: bold;
    }
</style>
<body>

</body>
<script>

    var frequency_list = [
'''

HTML_page_body = '''
          ];


    var color = d3.scale.linear()
            .domain([0,1,2,3,4,5,6,10,15,20,100])
            .range(["#ddd", "#ccc", "#bbb", "#aaa", "#999", "#888", "#777", "#666", "#555", "#444", "#333", "#222"]);

    d3.layout.cloud().size([850, 300])
            .words(frequency_list)
            .rotate(0)
            .fontSize(function(d) { return d.size; })
            .on("end", draw)
            .start();

    function draw(words) {
        d3.select("body").append("svg")
                .attr("width", 900)
                .attr("height", 350)
                .attr("class", "wordcloud")
                .append("g")
                // without the transform, words words would get cutoff to the left and top, they would
                // appear outside of the SVG area
                .attr("transform", "translate(370,200)")
                .selectAll("text")
                .data(words)
                .enter().append("text")
                .style("font-size", function(d) { return d.size + "px"; })
                .style("fill", function(d, i) { return color(i); })
                .attr("transform", function(d) {
                    return "translate(" + [d.x, d.y] + ")rotate(" + d.rotate + ")";
                })
                .text(function(d) { return d.text; });
    }
</script>

<div style="width: 40%;">
    <div class="legend">
        Commonly used words are larger and slightly faded in color.  Less common words are smaller and darker.
    </div>

</div>


</html>
'''


def read_words(file_name):
    '''
    Read a file with words and frequencies and store the data as a
    list of pairs:
    [(word1, freq1), (word1, freq2), ...]

    where word is a string and freq is an integer.
    '''
    result = []
    # put your code here
    file = open(file_name)
    for line in file:
        sub_list = line.split()
        sub_list[1] = int(sub_list[1])
        sub_list = tuple(sub_list)
        result.append(sub_list)

    return result


def get_top_words(words1, n):
    '''
    Receives a list of words and frequencies and returns the top n
    most frequent words with their respective frequencies
    >>> get_top_words([('w', 1), ('x', 5), ('#y', 8), ('#z', 3), ('@a', 4), ('b', 6)], n = 2)
    [('#y', 8), ('b', 6)]
    '''
    # put your code here
    top_words = []
    words1 = sorted(words1, key=lambda word2: word2[1], reverse=True)
    for i in range(n):
        word = words1[i]
        top_words.append(word)

    return top_words


def get_top_hashtags(words1, n):
    '''
    Receives a list of words and frequencies and returns the top n
    most frequent hashtags with their respective frequencies
    >>> get_top_hashtags([('w', 1), ('x', 5), ('#y', 8), ('#z', 3), ('@a', 4), ('b', 6)], n = 1)
    [('#y', 8)]
    '''
    # put your code here
    hashtag_word = []
    top_n_hashtag = []
    for word in words1:
        if word[0][0] == '#':
            hashtag_word.append(word)

    hashtag_word = sorted(hashtag_word, key=lambda word2: word2[1], reverse=True)
    for i in range(n):
        word = hashtag_word[i]
        top_n_hashtag.append(word)

    return top_n_hashtag


def get_top_users(words1, n):
    '''
    Receives a list of words and frequencies and returns the top n
    most frequent users with their respective frequencies
    >>> get_top_users([('w', 1), ('x', 5), ('#y', 8), ('#z', 3), ('@a', 4), ('b', 6)], 1)
    [('@a', 4)]
    '''
    # put your code here
    user = []
    top_n_user = []
    for word in words1:
        if word[0][0] == "@":
            user.append(word)

    user = sorted(user, key=lambda user1: user1[1], reverse=True)

    for i in range(n):
        user1 = user[i]
        top_n_user.append(user1)

    return top_n_user


def generate_cloud(words1, scale, file_name):
    '''
    Generate a HTML page that shows a word cloud with the words
    in the list words. The output HTML is written to file_name.
    The file can be open with the brovwser.
    The scale parameter controls the size of the words.
    '''
    print(words1)
    with open(file_name, 'w') as outfile:
        outfile.write(HTML_page_header)
        for w, f in words1:
            outfile.write("{text: '" + w + "', size:" + str(f * scale) + "},")
        outfile.write("{text: 'none', size: 0}\n")
        outfile.write(HTML_page_body)


# The file words.txt must be generated by process_tweets.py
# The result html files can be opened with a browser
words = read_words('words.txt')
generate_cloud(get_top_words(words, 100), 0.3, 'word_cloud.html')
generate_cloud(get_top_hashtags(words, 20), 5, 'hashtag_cloud.html')
generate_cloud(get_top_users(words, 30), 3, 'user_cloud.html')
