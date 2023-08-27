package com.kkankkan.EveryPeople.user.model;

import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonProperty;
//import com.kkankkan.EveryPeople.Friend.model.Friend;
import com.kkankkan.EveryPeople.post.model.Post;
import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import org.springframework.boot.context.properties.bind.DefaultValue;
import org.springframework.web.bind.annotation.RequestParam;

import javax.validation.constraints.Max;
import javax.validation.constraints.Size;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Entity(name = "user_details")
public class User {
	@GeneratedValue
	@JsonProperty("user-id")
	@Id
	private Integer userId;

	@Size(min = 4, max = 20)
	private String userName;
	private LocalDate birthDate;

	@JsonIgnore
	@OneToMany(mappedBy = "user", fetch = FetchType.EAGER)
	private List<Post> posts;

	@JsonIgnore
	@ManyToMany
	@JoinTable(
		name = "user_friends",
		joinColumns = @JoinColumn(name = "user_id"),
		inverseJoinColumns = @JoinColumn(name = "friend_id")
	)

	private Set<User> friends = new HashSet<>();

	public void addFriend(User friend) {
		friends.add(friend);
		friend.getFriends().add(this);
	}
}