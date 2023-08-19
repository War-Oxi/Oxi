package com.kkankkan.EveryPeople.post.model;

import com.kkankkan.EveryPeople.user.model.User;
import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Entity
public class Post {
	@GeneratedValue
	@Id
	private Integer postId;
	private String postTitle;
	private String postContent;

	//FetchType.LAZY로 설정할 경우

	/*
	 * EAGER 로딩 (FetchType.EAGER):
	 * Entity가 항상 즉시 로딩되는 방식
	 *
	 * LAZY 로딩 (FetchType.LAZY):
	 * 연관 엔티티가 실제로 사용될 때(접근될 때) 로딩되는 방식
	 */
	@ManyToOne(fetch = FetchType.EAGER)
	@JoinColumn(name = "user_id")
	private User user;
}
