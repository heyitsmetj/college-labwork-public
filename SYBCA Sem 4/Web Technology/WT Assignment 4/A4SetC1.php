<?php
interface Q
{
    public function enqueue($data);
    public function dequeue();
    public function isEmpty();
}

class Queue implements Q
{
    private $queue = []; 

    public function enqueue($data)
    {
        $this->queue[] = $data;
    }

    public function dequeue()
    {
        if (empty($this->queue)) 
        {
            return "<br>Queue is empty";
        } 
        else 
        {
            echo "<br>Removed Element: ";
            return array_shift($this->queue);
        }
    }

    public function isEmpty()
    {
        return empty($this->queue);
    }
}

$q1 = new Queue();
$q1->enqueue(10);
$q1->enqueue(20);

echo $q1->dequeue();
echo $q1->dequeue();
echo $q1->dequeue();
echo "<br>";

echo "IsEmpty?: " . ($q1->isEmpty() ? 'yes' : 'no');