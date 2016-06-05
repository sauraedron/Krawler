<h1> Krawler</h1>
Krawler is a program to download links according to filter. 
Pass in the <ol><li>html file path containing links</li><li> the destination folder and</li><li> the filter type.</li></ol>
Krawler will then parse the file to find download links matching the filter and run wget to download the files to your destination folder
<h2> Build Process </h2>
g++ -o Krawler Krawler.cpp -std=c++11
<h2> How to use</h2>
./Krawler /home/drn/Desktop/srcHtml.html /home/drn/Documents/destFolder mp3

