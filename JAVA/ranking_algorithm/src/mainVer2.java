class Student {
	private int num;
	private String name;
	private int score;

	Student(int num, String name, int score){
		this.num = num;
		this.name = name;
		this.score = score;
	}
	public int getScore(){
		return this.score;
	}

	public String toString(int rank){
		System.out.println(this.num + "\t" + this.name + "\t" + this.score + "\t" + rank);
		return null;
	}
}
