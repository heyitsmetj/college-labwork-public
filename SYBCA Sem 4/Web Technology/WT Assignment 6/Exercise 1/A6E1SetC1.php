<?php
$xml = new SimpleXMLElement('<cricket/>');

$players = [
    ["name" => "Hardik", "runs" => 100, "wickets" => 20],
    ["name" => "Shreyas", "runs" => 150, "wickets" => 10],
    ["name" => "Samson", "runs" => 80, "wickets" => 5],
    ["name" => "Dhoni", "runs" => 200, "wickets" => 15],
    ["name" => "Virat", "runs" => 120, "wickets" => 8]
];

foreach ($players as $player) {
    $p = $xml->addChild('player');
    $p->addChild('name', $player["name"]);
    $p->addChild('runs', $player["runs"]);
    $p->addChild('wickets', $player["wickets"]);
}

$xml->asXML('Cricket.xml');

echo "XML file 'Cricket.xml' has been created successfully.<br><br>";

echo "Cricket.xml File Contents: <br>";
$xml = new DOMDocument();
$xml->load("Cricket.xml");

$xml->preserveWhiteSpace = false;
$xml->formatOutput = true;

$xmlFormatted = htmlspecialchars($xml->saveXML());

echo "<pre>$xmlFormatted</pre>";

$xml = simplexml_load_file("Cricket.xml");

echo "<h2>Players who scored more than 100 runs</h2>";
echo "<table border='1' cellpadding='5' cellspacing='0'>";
echo "<tr><th>Name</th><th>Runs</th><th>Wickets</th></tr>";

foreach ($xml->player as $player) {
    if ((int)$player->runs > 100) {
        echo "<tr>";
        echo "<td>{$player->name}</td>";
        echo "<td>{$player->runs}</td>";
        echo "<td>{$player->wickets}</td>";
        echo "</tr>";
    }
}

echo "</table>";
?>
