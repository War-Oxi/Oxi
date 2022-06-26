package Major.Chapter_10;

abstract public class Animal {
    public int hp;
    public int damage; 
    public String name;
    public Animal(int hp, int damage, String name) {
        this.hp = hp;
        this.damage = damage;
        this.name = name;
    }

    public void attack(Animal enemy)   {
       enemy.hp -= damage;
    }

    public abstract void show();
}
