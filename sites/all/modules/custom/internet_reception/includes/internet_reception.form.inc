<?php

/**
 * @file
 * Form.
 */

/**
 * Form function.
 *
 * Field: name, email, agesubject, message, captcha and buttun submit.
 *
 * @return array
 *   Returns field values.
 */
function internet_reception_form($form, &$form_state) {
  $form = array();

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#required' => TRUE,
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#required' => TRUE,
  );

  $form['age'] = array(
    '#type' => 'textfield',
    '#title' => t('Age'),
    '#element_validate' => array('element_validate_integer_positive'),
    '#required' => TRUE,
  );

  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#required' => TRUE,
  );

  $form['message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message'),
    '#required' => TRUE,
  );

  $form['captcha'] = array(
    '#type' => 'captcha',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Validate field: name, email, subject, message.
 */
function internet_reception_form_validate($form, &$form_state) {
  if (mb_strlen($form_state['values']['name']) < 3) {
    form_set_error('name', t('Short name.'));
  }

  if (mb_strlen($form_state['values']['name']) > 15) {
    form_set_error('name', t('Long name.'));
  }

  if (!valid_email_address($form_state['values']['email'])) {
    form_set_error('email', t('Incorrect email.'));
  }

  if (mb_strlen($form_state['values']['subject']) > 63) {
    form_set_error('subject', t('Long subject.'));
  }

  if (mb_strlen($form_state['values']['message']) > 255) {
    form_set_error('message', t('Long message.'));
  }
}

/**
 * Submit information.
 */
function internet_reception_form_submit($form, &$form_state) {
  $valid_email = $form_state['values']['email'];
  $from = $form_state['values']['email'];
  $body[] = $form['name']['#title'] . ' : ' . $form_state['values']['name'] . ' ' . $form['age']['#title'] . ' : ' . $form_state['values']['age'] . ' ' . $form['message']['#title'] . ' : ' . $form_state['values']['message'];
  $to = variable_get('site_mail', '');
  $params = array(
    'body' => $body,
    'subject' => $form_state['values']['subject'],
  );

  if (drupal_mail('internet_reception_form', 'some_mail_key', $to, language_default(), $params, $from, TRUE)) {
    drupal_set_message(t('Message sent.'));
  }
  else {
    drupal_set_message(t('Message not sent. Please try again later.'));
  }
}
