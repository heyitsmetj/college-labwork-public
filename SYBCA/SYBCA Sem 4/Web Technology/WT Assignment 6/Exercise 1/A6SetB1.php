<?php
$xml = new SimpleXMLElement("<College/>");

$courses = [ 
    ['name' => 'Arts', 'level' => 'UnderGraduate', 'intake' => '300'],
    ['name' => 'Science', 'level' => 'UnderGraduate', 'intake' => '400'],
    ['name' => 'Commerce', 'level' => 'UnderGraduate', 'intake' => '200'],
    ['name' => 'Management', 'level' => 'PostGraduate', 'intake' => '100']
];

foreach ($courses as $course) 
{
    $c = $xml->addChild($course['name']);
    $c->addChild('Level', $course["level"]);
    $c->addChild('IntakeCapacity', $course["intake"]);
}

$xml->asXML('Course.xml');
echo "XML file 'Course.xml' has been created successfully.<br><br>";

echo "Course.xml File Contents: <br>";
$xml = new DOMDocument();
$xml->load("Course.xml");

$xml->preserveWhiteSpace = false;
$xml->formatOutput = true;

$xmlFormatted = htmlspecialchars($xml->saveXML());

echo "<pre>$xmlFormatted</pre>";

?>