<?php
$xml = new SimpleXMLElement("<ABC_College/>");


    $cad = $xml->addChild("Computer_Application_Department");
    $cad->addChild("Course", "BCA(Science)");
    $cad->addChild("Student_Strength", "80");
    $cad->addChild("Nomber_of_Teachers", "12");

$xml->asXML('College.xml');
echo "XML file 'College.xml' has been created successfully.<br><br>";

echo "College.xml File Contents: <br>";
$xml = new DOMDocument();
$xml->load("College.xml");

$xml->preserveWhiteSpace = false;
$xml->formatOutput = true;

$xmlFormatted = htmlspecialchars($xml->saveXML());

echo "<pre>$xmlFormatted</pre>";

?>