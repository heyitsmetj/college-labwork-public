<?php
$xml = new SimpleXMLElement('<Department/>');
$cs = $xml->addChild('ComputerScience');

$teachers = [
    ["name" => "Ram", "qualification" => "NET", "subject" => "Data Structures", "experience" => "5 years"],
    ["name" => "Shyaam", "qualification" => "NET", "subject" => "Machine Learning", "experience" => "7 years"],
    ["name" => "Anjali", "qualification" => "NET", "subject" => "Operating Systems", "experience" => "6 years"],
    ["name" => "Akanksha", "qualification" => "NET", "subject" => "Database Management", "experience" => "4 years"],
    ["name" => "Manoj", "qualification" => "NET", "subject" => "Computer Networks", "experience" => "8 years"]
];

foreach ($teachers as $teacher) {
    $t = $cs->addChild('Teacher');
    $t->addChild('Name', $teacher["name"]);
    $t->addChild('Qualification', $teacher["qualification"]);
    $t->addChild('SubjectTaught', $teacher["subject"]);
    $t->addChild('Experience', $teacher["experience"]);
}

$xml->asXML('Teacher.xml');
echo "XML file 'Teacher.xml' has been created successfully.<br><br>";

$xml = new DOMDocument();
$xml->load("Teacher.xml");

$xml->preserveWhiteSpace = false;
$xml->formatOutput = true;

$xmlFormatted = htmlspecialchars($xml->saveXML());

echo "<pre>$xmlFormatted</pre>";

?>
