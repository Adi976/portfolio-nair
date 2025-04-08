import React, { useState } from 'react';
import styled from 'styled-components';
import { motion, AnimatePresence } from 'framer-motion';
import { useInView } from 'react-intersection-observer';
import { FaPaperPlane, FaSpinner } from 'react-icons/fa';
import emailjs from 'emailjs-com';

const ContactSection = styled.section`
  padding: 120px 0;
  background-color: ${({ theme }) => theme.colors.white};
`;

const SectionTitle = styled.h2`
  font-size: 3rem;
  text-align: center;
  margin-bottom: 80px;
  font-weight: 700;
  color: ${({ theme }) => theme.colors.text};
`;

const ContactForm = styled.form`
  max-width: 600px;
  margin: 0 auto;
  background: white;
  padding: 40px;
  border-radius: 12px;
  box-shadow: 0 20px 40px rgba(0, 0, 0, 0.05);
`;

const FormGroup = styled.div`
  margin-bottom: 25px;
  position: relative;
`;

const Label = styled.label`
  display: block;
  margin-bottom: 8px;
  font-weight: 500;
  color: ${({ theme }) => theme.colors.text};
`;

const Input = styled.input`
  width: 100%;
  padding: 15px;
  border: 1px solid ${({ error }) => error ? '#ff4444' : '#e0e0e0'};
  border-radius: 12px;
  font-size: 1rem;
  transition: all 0.3s ease;

  &:focus {
    outline: none;
    border-color: ${({ theme }) => theme.colors.accent};
    box-shadow: 0 0 0 3px rgba(0, 113, 227, 0.1);
  }
`;

const TextArea = styled.textarea`
  width: 100%;
  padding: 15px;
  border: 1px solid ${({ error }) => error ? '#ff4444' : '#e0e0e0'};
  border-radius: 12px;
  font-size: 1rem;
  min-height: 150px;
  resize: vertical;
  transition: all 0.3s ease;

  &:focus {
    outline: none;
    border-color: ${({ theme }) => theme.colors.accent};
    box-shadow: 0 0 0 3px rgba(0, 113, 227, 0.1);
  }
`;

const ErrorMessage = styled.span`
  color: #ff4444;
  font-size: 0.85rem;
  position: absolute;
  bottom: -20px;
  left: 0;
`;

const SubmitButton = styled(motion.button)`
  width: 100%;
  padding: 16px;
  background-color: ${({ theme }) => theme.colors.accent};
  color: white;
  border: none;
  border-radius: 12px;
  font-size: 1rem;
  font-weight: 500;
  cursor: pointer;
  display: flex;
  align-items: center;
  justify-content: center;
  gap: 10px;
  transition: all 0.3s ease;

  &:disabled {
    background-color: #ccc;
    cursor: not-allowed;
  }
`;

const SuccessMessage = styled(motion.div)`
  background-color: #4caf50;
  color: white;
  padding: 20px;
  border-radius: 12px;
  margin-top: 20px;
  text-align: center;
`;

const Contact = () => {
  const [ref, inView] = useInView({
    triggerOnce: true,
    threshold: 0.1,
  });

  const [formData, setFormData] = useState({
    name: '',
    email: '',
    message: '',
  });

  const [errors, setErrors] = useState({});
  const [isSubmitting, setIsSubmitting] = useState(false);
  const [isSuccess, setIsSuccess] = useState(false);

  const validateForm = () => {
    const newErrors = {};
    
    if (!formData.name.trim()) {
      newErrors.name = 'Name is required';
    }
    
    if (!formData.email.trim()) {
      newErrors.email = 'Email is required';
    } else if (!/\S+@\S+\.\S+/.test(formData.email)) {
      newErrors.email = 'Email is invalid';
    }
    
    if (!formData.message.trim()) {
      newErrors.message = 'Message is required';
    }
    
    setErrors(newErrors);
    return Object.keys(newErrors).length === 0;
  };

  const handleChange = (e) => {
    const { name, value } = e.target;
    setFormData(prev => ({
      ...prev,
      [name]: value
    }));
    
    // Clear error when user starts typing
    if (errors[name]) {
      setErrors(prev => ({
        ...prev,
        [name]: ''
      }));
    }
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    
    if (!validateForm()) {
      return;
    }
    
    setIsSubmitting(true);
    
    try {
      // Replace these with your EmailJS credentials
      const templateParams = {
        from_name: formData.name,
        from_email: formData.email,
        message: formData.message,
      };
      
      await emailjs.send(
        'YOUR_SERVICE_ID',
        'YOUR_TEMPLATE_ID',
        templateParams,
        'YOUR_USER_ID'
      );
      
      setIsSuccess(true);
      setFormData({
        name: '',
        email: '',
        message: '',
      });
      
      setTimeout(() => {
        setIsSuccess(false);
      }, 5000);
    } catch (error) {
      console.error('Error sending email:', error);
      setErrors({
        submit: 'Failed to send message. Please try again later.'
      });
    } finally {
      setIsSubmitting(false);
    }
  };

  return (
    <ContactSection id="contact">
      <SectionTitle>Let's Connect</SectionTitle>
      <ContactForm
        ref={ref}
        onSubmit={handleSubmit}
        initial={{ opacity: 0, y: 20 }}
        animate={inView ? { opacity: 1, y: 0 } : {}}
        transition={{ duration: 0.5 }}
      >
        <FormGroup>
          <Label htmlFor="name">Name</Label>
          <Input
            type="text"
            id="name"
            name="name"
            value={formData.name}
            onChange={handleChange}
            error={errors.name}
            placeholder="Your Name"
          />
          {errors.name && <ErrorMessage>{errors.name}</ErrorMessage>}
        </FormGroup>
        
        <FormGroup>
          <Label htmlFor="email">Email</Label>
          <Input
            type="email"
            id="email"
            name="email"
            value={formData.email}
            onChange={handleChange}
            error={errors.email}
            placeholder="Your Email"
          />
          {errors.email && <ErrorMessage>{errors.email}</ErrorMessage>}
        </FormGroup>
        
        <FormGroup>
          <Label htmlFor="message">Message</Label>
          <TextArea
            id="message"
            name="message"
            value={formData.message}
            onChange={handleChange}
            error={errors.message}
            placeholder="Your Message"
          />
          {errors.message && <ErrorMessage>{errors.message}</ErrorMessage>}
        </FormGroup>
        
        <SubmitButton
          type="submit"
          disabled={isSubmitting}
          whileHover={{ scale: 1.02 }}
          whileTap={{ scale: 0.98 }}
        >
          {isSubmitting ? (
            <>
              <FaSpinner className="fa-spin" />
              Sending...
            </>
          ) : (
            <>
              <FaPaperPlane />
              Send Message
            </>
          )}
        </SubmitButton>
        
        {errors.submit && (
          <ErrorMessage style={{ position: 'static', marginTop: '10px' }}>
            {errors.submit}
          </ErrorMessage>
        )}
        
        <AnimatePresence>
          {isSuccess && (
            <SuccessMessage
              initial={{ opacity: 0, y: 20 }}
              animate={{ opacity: 1, y: 0 }}
              exit={{ opacity: 0, y: -20 }}
            >
              Thank you for your message! I'll get back to you soon.
            </SuccessMessage>
          )}
        </AnimatePresence>
      </ContactForm>
    </ContactSection>
  );
};

export default Contact; 