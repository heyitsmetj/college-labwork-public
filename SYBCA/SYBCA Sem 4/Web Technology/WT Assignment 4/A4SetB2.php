<?php
class Employee
{
    private $id;
    private $name;
    private $department;
    private $salary;

    public function __construct($id, $name, $department, $salary)
    {
        $this->id = $id;
        $this->name = $name;
        $this->department = $department;
        $this->salary = $salary;
    }

    public function getSalary()
    {
        return $this->salary;
    }

    public function getName()
    {
        return $this->name;
    }

    public function getDepartment()
    {
        return $this->department;
    }
}

class Manager extends Employee
{
    private $bonus;

    public function __construct($id, $name, $department, $salary, $bonus)
    {
        parent::__construct($id, $name, $department, $salary);
        $this->bonus = $bonus;
    }

    public function getBonus()
    {
        return $this->bonus;
    }

    public function getTotalSalary()
    {
        return $this->getSalary() + $this->getBonus();
    }
}

$managers = [
    new Manager(1, "Jayehs", "HR", 50000, 5000),
    new Manager(2, "Jayanti", "Finance", 60000, 8000),
    new Manager(3, "Jigesh", "IT", 55000, 6000),
    new Manager(4, "Rahul", "Marketing", 65000, 7000),
    new Manager(5, "Ram", "Sales", 70000, 9000),
    new Manager(6, "Shyam", "Operations", 48000, 4000),
];

$maxTotalSalaryManager = $managers[0];
foreach ($managers as $manager) {
    if ($manager->getTotalSalary() > $maxTotalSalaryManager->getTotalSalary()) {
        $maxTotalSalaryManager = $manager;
    }
}

echo "Manager with the Maximum Total Salary:<br>";
echo "Name: " . $maxTotalSalaryManager->getName() . "<br>";
echo "Department: " . $maxTotalSalaryManager->getDepartment() . "<br>";
echo "Salary: " . $maxTotalSalaryManager->getSalary() . "<br>";
echo "Bonus: " . $maxTotalSalaryManager->getBonus() . "<br>";
echo "Total Salary (Salary + Bonus): " . $maxTotalSalaryManager->getTotalSalary() . "<br>";

?>
