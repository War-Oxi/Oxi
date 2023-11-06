// script.js
document.getElementById('postForm').addEventListener('submit', function(e) {
    e.preventDefault();
  
    var title = document.getElementById('title').value;
    var content = document.getElementById('content').value;
  
    fetch('../api/posts', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({ title: title, content: content }),
    })
    .then(response => response.json())
    .then(data => {
      console.log('Success:', data);
      alert('Post created!');
      // Optionally reset the form or redirect the user
      document.getElementById('postForm').reset();
    })
    .catch((error) => {
      console.error('Error:', error);
    });
  });
  