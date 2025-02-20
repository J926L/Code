// 表单验证
document.addEventListener('DOMContentLoaded', function() {
    const forms = document.querySelectorAll('.auth-form');
    
    forms.forEach(form => {
        form.addEventListener('submit', function(e) {
            e.preventDefault();
            
            // 获取表单元素
            const username = form.querySelector('#username');
            const email = form.querySelector('#email');
            const password = form.querySelector('#password');
            const confirmPassword = form.querySelector('#confirm-password');
            
            // 清除之前的错误提示
            clearErrors(form);
            
            // 验证用户名
            if (username && username.value.length < 3) {
                showError(username, '用户名至少需要3个字符');
                return;
            }
            
            // 验证邮箱
            if (email && !validateEmail(email.value)) {
                showError(email, '请输入有效的邮箱地址');
                return;
            }
            
            // 验证密码
            if (password && password.value.length < 6) {
                showError(password, '密码至少需要6个字符');
                return;
            }
            
            // 验证确认密码
            if (confirmPassword && password.value !== confirmPassword.value) {
                showError(confirmPassword, '两次输入的密码不一致');
                return;
            }
            
            // 表单验证通过，模拟提交
            alert('注册成功！');
            form.reset();
        });
    });
});

// 显示错误信息
function showError(input, message) {
    const formGroup = input.parentElement;
    const error = document.createElement('div');
    error.className = 'error-message';
    error.textContent = message;
    formGroup.appendChild(error);
    input.classList.add('error');
}

// 清除错误信息
function clearErrors(form) {
    const errors = form.querySelectorAll('.error-message');
    errors.forEach(error => error.remove());
    
    const inputs = form.querySelectorAll('input');
    inputs.forEach(input => input.classList.remove('error'));
}

// 邮箱格式验证
function validateEmail(email) {
    const re = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return re.test(String(email).toLowerCase());
}
