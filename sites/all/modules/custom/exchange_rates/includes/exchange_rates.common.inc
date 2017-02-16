<?php

/**
 * @file
 * Common file.
 */

/**
 * Writing data in data base.
 *
 * @param mixed $form
 *   Return exchange_rates_config_form.
 * @param mixed $form_state
 *   Return exchange_rates_config_form.
 */
function exchange_rates_form_rate_submit($form, &$form_state) {

  $values = array(
    'code' => $form_state['values']['code'],
    'value' => $form_state['values']['value'],
    'timestamp' => strtotime($form_state['values']['timestamp']['month'] . '/' . $form_state['values']['timestamp']['day'] . '/' . $form_state['values']['timestamp']['year']),
  );
  $entity = entity_create('exchange_rates_entity', $values);
  entity_save('exchange_rates_entity', $entity);
}
