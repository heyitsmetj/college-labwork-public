<?php
$xml = new SimpleXMLElement('<subjects/>');

$subjects = [
    ["code" => "BCA 245", "name" => "Web Technology Laboratory"],
    ["code" => "BCA 101", "name" => "Computer Programming"],
    ["code" => "BCA 202", "name" => "Database Management System"],
    ["code" => "BCA 303", "name" => "Operating Systems"],
    ["code" => "BCA 404", "name" => "Software Engineering"]
];

foreach ($subjects as $subject) {
    $s = $xml->addChild('subject');
    $s->addChild('code', $subject["code"]);
    $s->addChild('name', $subject["name"]);
}

$xml->asXML('Subjects.xml');

echo "XML file 'Subjects.xml' has been created successfully.<br><br>";

echo "Subjects.xml File Contents: <br>";
$xml = new DOMDocument();
$xml->load("Subjects.xml");

$xml->preserveWhiteSpace = false;
$xml->formatOutput = true;

$xmlFormatted = htmlspecialchars($xml->saveXML());

echo "<pre>$xmlFormatted</pre>";

$xml = simplexml_load_file("Subjects.xml");

foreach ($xml->subject as $subject) {
    if (trim($subject->name) == "Web Technology Laboratory") {
        echo "<h2>Subject Code for 'Web Technology Laboratory': {$subject->code}</h2>";
    }
}
?>
