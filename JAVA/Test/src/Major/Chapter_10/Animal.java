package Major.Chapter_10;

abstract public class Animal {
    public int hp;
    public int damage; 
    public Animal(int hp, int damage) {
        this.hp = hp;
        this.damage = damage;
    }

    public void attack(Animal enemy)   {
       enemy.hp -= damage;
    }

    public abstract void show();
}
