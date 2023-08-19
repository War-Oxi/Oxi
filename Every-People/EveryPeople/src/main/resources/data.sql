insert into user_details(user_id, user_name, birth_date)
values(10001, '깜태지1', current_date());

insert into user_details(user_id, user_name, birth_date)
values(10002, '깜태지2', current_date());

insert into user_details(user_id, user_name, birth_date)
values(10003, '깜태지3', current_date());

insert into user_details(user_id, user_name, birth_date)
values(10004, '깜태지4', current_date());

insert into user_details(user_id, user_name, birth_date)
values(10005, '깜태지5', current_date());

insert into user_details(user_id, user_name, birth_date)
values(10006, '깜태지6', current_date());

--insert into friend(user_id, friend_id)
--values(10001, 10002);
--
--insert into friend(user_id, friend_id)
--values(10001, 10003);
--
--insert into friend(user_id, friend_id)
--values(10001, 10004);
--
--insert into friend(user_id, friend_id)
--values(10002, 10003);
--
--insert into friend(user_id, friend_id)
--values(10002, 10004);

insert into post(post_id, post_title, post_content, user_id)
values(20001, 'Spring 공부 중', '저는 현재 Spring을 공부하고 있습니다', 10001);

insert into post(post_id, post_title, post_content, user_id)
values(20002, 'AWS 공부 중', '저는 현재 AWS를 공부하고 있습니다', 10001);

insert into post(post_id, post_title, post_content, user_id)
values(20003, 'Azure 공부 중', '저는 현재 Azure를 공부하고 있습니다', 10002);

insert into post(post_id, post_title, post_content, user_id)
values(20004, 'GCP 공부 중', '저는 현재 GCP를 공부하고 있습니다', 10002);
