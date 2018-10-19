<?php 
//Get all the links of the top100 lyrics
$top100Page = new DOMDocument();
$top100page->loadHTMLFile("http://www.lyricsfreak.com/top/index.html");
$xpath = new DOMXPath($top100Page);
$top100song = $xpath->query("//*[@class='song_index']");
echo $top100song;
//For Each link
//get thhe lyrics and write them in a file in this form [song_name,lyrics]
?>